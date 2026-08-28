SWIFT
=====

SWIFT is a cosmological simulation code (`swiftsim.com <https://swiftsim.com>`_) developed
at Durham University. This benchmark drives SWIFT's own HDF5 snapshot-writing binary
(``write-hdf5-output``) through h5bench, so that SWIFT's real I/O pattern — rather
than a synthetic one — can be measured and used to inform HDF5 development work.

You can find more information in the SWIFT `GitHub repository
<https://github.com/SWIFTSIM/swiftsim>`_.

Requirements
------------

This benchmark requires:

- **HDF5** (parallel build) — e.g. version 1.14.4
- **MPI** — an MPI compiler wrapper (e.g. ``mpicc``)
- **GSL** — required by SWIFT's ``write_output_single()``
- An Intel or GNU compiler toolchain compatible with the above

Configuration
-------------

You can configure the SWIFT benchmark with the following options.

====================== ==============================================================================
**Parameter**          **Description**
====================== ==============================================================================
``numberOfParticles``  Number of particles to generate and write in the output snapshot
``parameter-file``     Path to SWIFT's own YAML parameter file (e.g.
                       ``HDF5WritingParameters.yml``), controlling SPH and snapshot options
====================== ==============================================================================

The referenced parameter file uses SWIFT's native YAML format and includes 
SWIFT-specific options such as:

====================== ==============================================================================
**Parameter**          **Description**
====================== ==============================================================================
``resolution_eta``     Target smoothing length in units of the mean inter-particle separation
``CFL_condition``      Courant-Friedrich-Levy condition for time integration
``select_output_on``   Enables per-field output selection; ``0`` writes all fields by default
====================== ==============================================================================

JSON Configuration (recommended)
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

To run an instance of the SWIFT benchmark you need to include the following in the
``benchmarks`` property of your ``configuration.json`` file:

.. code-block::

    {
        "benchmark": "swift",
        "file": "swift",
        "configuration": {
            "numberOfParticles": 999999,
            "parameter-file": "../swift/write-hdf5-output/HDF5WritingParameters.yml"
        }
    }

Notes
-----
Note that the ``/Cells`` group in the output is currently empty, as the benchmark
drives SWIFT's I/O path directly without the mesh-building step
(``space_regrid``/``space_split``) that populates it in a full SWIFT run.
